import os
import shutil

import vitis


PRJ_NAME = 'sorting_network'
# TOP_DIR = os.path.dirname(os.path.abspath(__file__))
TOP_DIR = os.getcwd()
CFG_PATH = os.path.join(TOP_DIR, 'hls_config.cfg')

workspace = os.path.join(TOP_DIR, '_hls-ws')
if os.path.exists(workspace):
    shutil.rmtree(workspace)

# Initialize session
client = vitis.create_client()
client.set_workspace(path=workspace)

# Create component. Create new config file in the component folder of the workspace
comp = client.create_hls_component(
    name=PRJ_NAME,
    cfg_file=CFG_PATH,
    template='empty_hls_component'
)

# Get handle of config file, then programmatically set desired options
cfg_file = client.get_config_file(path=CFG_PATH)
cfg_file.set_value (key='part', value='xc7z020clg400-1') 
cfg_file.set_value (section='hls', key='syn.file', value=os.path.join(TOP_DIR, 'hls.cpp'))
cfg_file.set_values(section='hls', key='tb.file', values=[os.path.join(TOP_DIR, 'tb.cpp')])
cfg_file.set_value (section='hls', key='syn.top', value='hls_sorting_network_9')
cfg_file.set_value (section='hls', key='clock', value='10')  # in [ns]
cfg_file.set_value (section='hls', key='flow_target', value='vivado')
# cfg_file.set_value (section='hls', key='syn.directive.interface', value='pointer_basic mode=m_axi depth=1 d')

# Run flow steps
comp = client.get_component(name=PRJ_NAME)
comp.run(operation='C_SIMULATION')
comp.run(operation='SYNTHESIS')
comp.run(operation='CO_SIMULATION')
